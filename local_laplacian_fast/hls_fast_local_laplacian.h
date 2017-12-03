#ifndef _HLS_FAST_LOCAL_LAPLACIAN_
#define _HLS_FAST_LOCAL_LAPLACIAN_


#include "opencv2/core/core.hpp"		// cv::Mat

// Max. image size
#define		_MAX_ROWS_		1024
#define		_MAX_COLS_		1024

// Max. number of pyramid levels
#define		_MAX_LEVELS_		9

// Data types
#define		_MAT_TYPE_			HLS_32FC1

typedef		float			data_in_t;		// Input data type
typedef		float			data_out_t;		// output data type

typedef		float			pipe_t;


void hls_local_laplacian_wrap(cv::Mat& src, cv::Mat& dst, float sigma, float fact, int N);

void hls_local_laplacian(float* I, float** lap, float** dst, int* pyr_height, int* pyr_width,
		int num_levels, float sigma, float fact, int N);

void gaussian_pyramid(float* src, float** dst, int n_levels, int* pyr_height, int* pyr_width);

void laplacian_pyramid(float* src, float** dst, int n_levels, int* pyr_height, int* pyr_width);

void reconstruct(float** src, float* dst, int num_levels, int* rows, int* cols);

void remap(float* src, float* dst, float ref, float fact, float sigma, int rows, int cols);


#endif
