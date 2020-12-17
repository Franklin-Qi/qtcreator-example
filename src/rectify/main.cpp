#include "MainWindow.h"

#include <QApplication>

#include <opencv2/core/utility.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <iostream>
using namespace cv;
using namespace std;
#define ERROR 1234

//度数转换
double DegreeTrans(double theta)
{
    double res = theta / CV_PI * 180;
    return res;
}

//逆时针旋转图像degree角度（原尺寸）
void rotateImage(Mat src, Mat& img_rotate, double degree)
{
    //旋转中心为图像中心
    Point2f center;
    center.x = float(src.cols / 2.0);
    center.y = float(src.rows / 2.0);
    int length = 0;
    length = sqrt(src.cols*src.cols + src.rows*src.rows);
    //计算二维旋转的仿射变换矩阵
    Mat M = getRotationMatrix2D(center, degree, 1);
    warpAffine(src, img_rotate, M, Size(length, length), 1, 0, Scalar(255, 255, 255));//仿射变换，背景色填充为白色
}

//通过霍夫变换计算角度
double CalcDegree(const Mat &srcImage, Mat &dst)
{
    Mat midImage, dstImage;
    //GaussianBlur (srcImage, srcImage, Size(7,7), 0);
    //imshow ("gaussianblue", srcImage);


    Canny(srcImage, midImage, 50, 200, 3);
    cvtColor(midImage, dstImage, CV_GRAY2BGR);

    //通过霍夫变换检测直线
    vector<Vec2f> lines;
    HoughLines(midImage, lines, 1, CV_PI / 180, 300, 0, 0);//第5个参数就是阈值，阈值越大，检测精度越高
    //cout << lines.size() << endl;

    //由于图像不同，阈值不好设定，因为阈值设定过高导致无法检测直线，阈值过低直线太多，速度很慢
    //所以根据阈值由大到小设置了三个阈值，如果经过大量试验后，可以固定一个适合的阈值。

    if (!lines.size())
    {
        HoughLines(midImage, lines, 1, CV_PI / 180, 200, 0, 0);
    }
    //cout << lines.size() << endl;

    if (!lines.size())
    {
        HoughLines(midImage, lines, 1, CV_PI / 180, 150, 0, 0);
    }
    if (!lines.size())
    {
        HoughLines(midImage, lines, 1, CV_PI / 180, 100, 0, 0);
    }

    //cout << lines.size() << endl;
    if (!lines.size())
    {
        cout << "没有检测到直线！" << endl;
        return ERROR;
    }
    float sum = 0;
    int n = 0;
    //依次画出每条线段
    cout << "lines.size() = " << lines.size () << endl;
    size_t i = 0;
    for (i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));

        cout << i << ", " << "DegreeTrans() = " << DegreeTrans (theta) << endl;

        //只选角度最小的作为旋转角度
        if((DegreeTrans(theta) >= 88.5) && (DegreeTrans(theta) <= 91))
        {
            n +=1;
            continue;
        }
        /*
        if((DegreeTrans(theta) >= 178.5))
        {
            n +=1;
            continue;
        }
        */
        if((DegreeTrans(theta) <= 1))
        {
            n +=1;
            continue;
        }
        sum += theta;
        cout << "sum = " << sum << endl;
        line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA); //Scalar函数用于调节线段颜色
        imshow("直线探测效果图", dstImage);
    }

    if (lines.size () - n == 0 || sum == 0)
    {
        return 0.0;
    }
    float average = sum / (lines.size() - n ); //对所有角度求平均，这样做旋转效果会更好
    cout << "average = " << average << ", n = " << n << endl;
    cout << "average theta:" << average << endl;
    double angle = DegreeTrans(average) ;
    cout << "angle = " << angle;

    /*
    if(angle >= 135)
        angle = angle - 180;
    else if(angle >= 90)
        angle =angle - 90;
    else if(angle >= 45)
        angle =  angle - 90;
    cout << "angle11 = " << angle;
    */
    angle = angle - 90;

    rotateImage(dstImage, dst, angle);
    imshow("直线探测效果图2", dstImage);
    return angle;
}

void ImageRecify(const char* pInFileName, const char* pOutFileName)
{
    double degree;
    Mat src = imread(pInFileName);
    imshow("原始图", src);
    int srcWidth, srcHight;
    srcWidth = src.cols;
    srcHight = src.rows;
    cout << srcWidth << "   " << srcHight << endl;
    Mat dst;
    src.copyTo(dst);
    //倾斜角度矫正
    degree = CalcDegree(src, dst);
    if (degree == ERROR)
    {
        cout << "矫正失败！" << endl;
        return;
    }
    rotateImage(src, dst, degree);
    cout << "angle:" << degree << endl;
    imshow("旋转调整后", dst);

    Mat resulyImage = dst(Rect(0, 0, srcWidth, srcHight)); //根据先验知识，估计好文本的长宽，再裁剪下来
    imshow("裁剪之后", resulyImage);
    imwrite("recified.jpg", resulyImage);
}

/*
int ImageRectify(const char * pInFileName)
{
    double degree;

    Mat src = imread(pInFileName);
    Mat dst;
    //倾斜角度矫正
    degree = CalcDegree(src,dst);
    MYLOG << "degree = " << degree;

    if (fabs (degree - ERROR) < 1e-15)
    {
        MYLOG << "矫正失败！" ;
        return -1;
    }
    if(fabs(degree) < 1e-15 + 0.4)
    {
        MYLOG <<"already right, so return straight!";
        return -1;

    }
    else
    {   src = imread(pInFileName);
        rotateImage(src, dst, degree);
        imwrite("/tmp/scanner/scan1.png",dst);
        return 0;
    }

}
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageRecify("/home/yusq/scanner01.jpg", "FinalImage.jpg");
    waitKey();

    return a.exec();
}
