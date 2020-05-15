#include "detect_shapes.hpp"

#define NUM_IMAGES 45

int main(void)
{
  char * filepath = new char[100];
  char * out_filepath = new char[100];

  for(int img = 0; img < NUM_IMAGES ; img++) // for all images
  {
    sprintf(filepath, "/home/fitimhalimi/ws/prototype_ws/ShapeDetector/test/img_%i.png", img); // changing the path
    DetectShapes shapes(cv::imread(filepath));

    cv::Mat combine;
    cv::hconcat(shapes.getOriginalImage(), shapes.getShapesImage(), combine);//Syntax-> hconcat(source1,source2,destination);
    cv::resizeWindow("Combine", 1000,500);
    cv::imshow("Combine", combine);
    cv::waitKey(0);

    switch(shapes.getShape())
    {
      case DetectShapes::Shapes::Triangle:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Triangle/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Rectangle:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Rectangle/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Square:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Square/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Pentagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Pentagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Hexagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Hexagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Heptagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Heptagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Octagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Octagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Nonagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Nonagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Decagon:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Decagon/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Circle:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Circle/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Ellipse:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Ellipse/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
      case DetectShapes::Shapes::Unknown:
      {
        sprintf(out_filepath, "/home/jimmyhalimi/ws/prototype_ws/ShapeDetector/result/Unknown/img_%i.png", img); // changing the path
        cv::imwrite(out_filepath, shapes.getShapesImage());
        break;
      }
    }
  }

  return 0;
}