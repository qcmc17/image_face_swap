#ifndef FACE_LAND_MARK_H
#define FACE_LAND_MARK_H

#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>

namespace fs {
	using namespace dlib;
class FaceLandMark {
	private:
		frontal_face_detector detector;
		shape_predictor sp;
	
	public:
		FaceLandMark(const std::string& dat): detector(get_frontal_face_detector()) {
            std::fstream stream(dat, std::ios::in | std::ios::binary);
            deserialize(sp, stream);
			//deserialize(dat) >> sp;
		}


		auto getLandMark(const std::string& image) {
			
			array2d<rgb_pixel> img;
			load_image(img, image);

			std::vector<rectangle> dets = detector(img);
			std::cout << "Number of faces detected: " << dets.size() << std::endl;

			std::vector<cv::Point2f> ans;
			for(size_t i = 0; i < dets.size(); ++i) {
				full_object_detection shape = sp(img, dets[i]);
				std::cout << "number of parts: "<< shape.num_parts() << std::endl;
				for(size_t j = 0; j < shape.num_parts(); ++j) {
					ans.push_back(cv::Point2f(shape.part(j).x(), shape.part(j).y()));
					//std::cout << ans.back() << std::endl;
				}
			}
			return ans;
		}
};

}

#endif
