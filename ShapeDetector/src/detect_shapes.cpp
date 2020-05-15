#include "detect_shapes.hpp"

DetectShapes::DetectShapes(cv::Mat src_image)
{
  if (src_image.empty())
  {
    std::cerr << "Image is not loaded\n";
    return;
  }

  this->src_image = src_image;

  // Convert to grayscale
	cv::Mat gray;
	cv::cvtColor(src_image, gray, CV_BGR2GRAY);

	// Use Canny instead of threshold to catch squares with gradient shading
	cv::Mat bw;
	cv::Canny(gray, bw, 0, 50, 5);

	// Find contours
	std::vector<std::vector<cv::Point> > contours;
	cv::findContours(bw.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	std::vector<cv::Point> approx;
	this->dst_image = src_image.clone();

	for (int i = 0; i < contours.size(); i++)
	{
		// Approximate contour with accuracy proportional
		// to the contour perimeter
		cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

		// Skip small or non-convex objects 
		if (std::fabs(cv::contourArea(contours[i])) < 3000|| !cv::isContourConvex(approx))
			continue;

    switch(approx.size())
    {
      case 3:
      {
        setLabel(this->dst_image, "Triangle", contours[i]);
        this->detected_shape = Shapes::Triangle;
        break;
      }
      case 4:
      {
        cv::Rect rect = cv::boundingRect(contours[i]);

        if(static_cast<double>(rect.width/rect.height) == 1.0)
        {
          setLabel(this->dst_image, "Squar", contours[i]);
          this->detected_shape = Shapes::Square;
          //std::cout << "X: " << rect.x << ", Y: " << rect.y << ", W: " << rect.width << ", H: " << rect.height << std::endl;
        }
        else
        {
          setLabel(this->dst_image, "Rect", contours[i]);
          this->detected_shape = Shapes::Rectangle;
        }
        
        break;
      }
      case 5:
      {
        setLabel(this->dst_image, "Penta", contours[i]);
        this->detected_shape = Shapes::Pentagon;
        break;
      }
      case 6:
      {
        setLabel(this->dst_image, "Hexa", contours[i]);
        this->detected_shape = Shapes::Hexagon;
        break;
      }
      case 7:
      {
        setLabel(this->dst_image, "Hepta", contours[i]);
        this->detected_shape = Shapes::Heptagon;
        break;
      }
      case 8:
      {
        setLabel(this->dst_image, "Octa", contours[i]);
        this->detected_shape = Shapes::Octagon;
        break;
      }
      case 9:
      {
        setLabel(this->dst_image, "Nona", contours[i]);
        this->detected_shape = Shapes::Nonagon;
        break;
      }
      case 10:
      {
        setLabel(this->dst_image, "Deca", contours[i]);
        this->detected_shape = Shapes::Decagon;
        break;
      }
      default:
      {
        // Detect and label circles
        double area = cv::contourArea(contours[i]);
        cv::Rect r = cv::boundingRect(contours[i]);
        int radius = r.width / 2;

        if(std::abs(1 - ((double)r.width / r.height)) <= 0.5 && std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.5)
        {
          setLabel(this->dst_image, "Circle", contours[i]);
        }
        else if(std::abs(1 - ((double)r.width / r.height)) <= 0.5 && std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.5)
        {
          setLabel(this->dst_image, "Elipse", contours[i]);
        }
        else
        {
          setLabel(this->dst_image, "Unknown", contours[i]);
        }
        break;
      }
    }
	}
}

/**
 * Helper function to find a cosine of angle between vectors
 * from pt0->pt1 and pt0->pt2
 */
double DetectShapes::angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

/**
 * Helper function to display text in the center of a contour
 */
void DetectShapes::setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour)
{
	int fontface = cv::FONT_HERSHEY_SIMPLEX;
	double scale = 0.4;
	int thickness = 1;
	int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::Rect r = cv::boundingRect(contour);

	cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255,255,255), CV_FILLED);
	cv::putText(im, label, pt, fontface, scale, CV_RGB(0,0,0), thickness, 8);
}