#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


 int main()
 {
   Point2f srcTri[3];
   Point2f dstTri[3];

   Mat rot_mat( 2, 3, CV_32FC1 );
   Mat warp_mat( 2, 3, CV_32FC1 );
   Mat src, warp_dst, warp_rotate_dst;

   src = imread( "pin.jpg", 1 );

   warp_dst = Mat::zeros( src.rows, src.cols, src.type() );

   srcTri[0] = Point2f( 0,0 );
   srcTri[1] = Point2f( src.cols - 1, 0 );
   srcTri[2] = Point2f( 0, src.rows - 1 );

   dstTri[0] = Point2f( src.cols*0.0+3, src.rows*0.33 );
   dstTri[1] = Point2f( src.cols*0.85, src.rows*0.25 );
   dstTri[2] = Point2f( src.cols*0.15, src.rows*0.7 );


   warp_mat = getAffineTransform( srcTri, dstTri );
	
   warpAffine( src, warp_dst, warp_mat, warp_dst.size() );


   Point center = Point( warp_dst.cols/2, warp_dst.rows/2 );
   double angle = -50.0;
   double scale = 0.6;

   rot_mat = getRotationMatrix2D( center, angle, scale );

   warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );

   namedWindow( "1", CV_WINDOW_AUTOSIZE );
   imshow( "1", src );

   namedWindow("2", CV_WINDOW_AUTOSIZE );
   imshow( "2", warp_dst );

   namedWindow( "3", CV_WINDOW_AUTOSIZE );
   imshow( "3", warp_rotate_dst );

   /// Wait until user exits the program
   waitKey(0);

   return 0;
  }
