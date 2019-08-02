set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/example)

add_executable(example example.cpp net_init.cpp run.cpp)

file(GLOB_RECURSE DPU_CODES ${PROJECT_SOURCE_DIR}/model/dpu_superpoint.elf)

target_link_libraries(example
${DPU_CODES}
${OpenCV_LIBS}
# /home/tsui/yujc/caffe-ssd/build/lib/libcaffe.so
# /usr/lib/x86_64-linux-gnu/libglog.so
# /usr/lib/x86_64-linux-gnu/libboost_system.so
${PROJECT_SOURCE_DIR}/lib/libsuperpoint.so
)
