#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>

class DetectShapes
{
  public:

    enum class Shapes : uint8_t
    {
      BEGIN = 0,
      Triangle = BEGIN,
      Rectangle,
      Square,
      Pentagon,
      Hexagon,
      Heptagon,
      Octagon,
      Nonagon,
      Decagon,
      Circle,
      Ellipse,
      Unknown,
      END
    };

    DetectShapes(cv::Mat src_image);
    void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);
    double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
    
    inline cv::Mat getOriginalImage(void)
    {
      return this->src_image;
    }

    inline cv::Mat getShapesImage(void)
    {
      return this->dst_image;
    }

    inline Shapes getShape(void)
    {
      return detected_shape;
    }

    ~DetectShapes() = default;
    
  private:
    cv::Mat src_image, dst_image;
    Shapes detected_shape;
};