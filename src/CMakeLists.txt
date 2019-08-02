set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
SET(SRC_LIST SuperPoint.cpp)
add_library(${PROJECT_NAME} SHARED ${SRC_LIST}) 

file(GLOB_RECURSE DPU_CODES ${PROJECT_SOURCE_DIR}/model/dpu_superpoint.elf)

target_link_libraries(${PROJECT_NAME}
${DPU_CODES}
${OpenCV_LIBS}
# /home/tsui/yujc/caffe-ssd/build/lib/libcaffe.so
# /usr/lib/x86_64-linux-gnu/libglog.so
# /usr/lib/x86_64-linux-gnu/libboost_system.so
)
target_link_libraries(${PROJECT_NAME} pthread hineon n2cube dputils)
