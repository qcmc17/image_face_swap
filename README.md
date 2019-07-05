This code repository is based on [Face Swap using OpenCV ( C++ / Python )](https://www.learnopencv.com/face-swap-using-opencv-c-python/).
Compare with [Face Swap using OpenCV ( C++ / Python )](https://www.learnopencv.com/face-swap-using-opencv-c-python/), in this repository, we use dlib(http://dlib.net/) for face keypoint detection.


1.Requirement
    dlib(for facial landmark detecion)
    opencv(face swap)
    cmake
    g++ with c++11/14

2.Build
    mkdir build &&& cd build
    cmake ..
    make

3.Usage
    ./faceswap shape_predictor_68_face_landmarks.dat src.png dst.png save_name.png
    

More please see the following [blog post](https://www.learnopencv.com/face-swap-using-opencv-c-python/) for more details about this code
