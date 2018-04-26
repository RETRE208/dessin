#include "texture.h"

void Texture::filter(ofImage* image)
{
	image_width = image->getWidth();
	image_height = image->getHeight();
	const int kernel_size = 3;
	const int kernel_offset = kernel_size / 2;
	const int color_component_count = 4;
	int x, y;
	int i, j;
	int c;
	int pixel_index_img_src;
	int pixel_index_img_dst;
	int kernel_index;
	float kernel_value;

	ofPixels pixel_array_src = image->getPixels();
	ofPixels pixel_array_dst = image->getPixels();
	ofColor pixel_color_src;
	ofColor pixel_color_dst;

	float sum[color_component_count];
	for (y = 1; y < image_height - 1; ++y)
	{
		for (x = 1; x < image_width - 1; ++x)
		{
			for (c = 0; c < color_component_count; ++c)
				sum[c] = 0;

			pixel_index_img_dst = (image_width * y + x) * color_component_count;

			for (j = -kernel_offset; j <= kernel_offset; ++j)
			{
				for (i = -kernel_offset; i <= kernel_offset; ++i)
				{
					pixel_index_img_src = (image_width * (y - j) + (x - i)) * color_component_count;

					pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);

					kernel_index = kernel_size * (j + kernel_offset) + (i + kernel_offset);

					switch (kernel_type)
					{
					case ConvolutionKernel::emboss:
						kernel_value = convolution_kernel_emboss.at(kernel_index);
						break;

					case ConvolutionKernel::sharpen:
						kernel_value = convolution_kernel_sharpen.at(kernel_index);
						break;

					case ConvolutionKernel::edge_detect:
						kernel_value = convolution_kernel_edge_detect.at(kernel_index);
						break;

					case ConvolutionKernel::blur:
						kernel_value = convolution_kernel_blur.at(kernel_index);
						break;
					}

					for (c = 0; c < color_component_count; ++c)
					{
						sum[c] = sum[c] + kernel_value * pixel_color_src[c];
					}
				}
			}
			for (c = 0; c < color_component_count; ++c)
			{
				pixel_color_dst[c] = (int)ofClamp(sum[c], 0, 255);
			}
			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
	}
	image->setFromPixels(pixel_array_dst);
}

void Texture::changeOpacity(ofImage* image, int alpha)
{
	image_width = image->getWidth();
	image_height = image->getHeight();
	const int color_component_count = 4;
	int x, y;
	int c;
	int pixel_index_img_src;
	int pixel_index_img_dst;
	ofPixels pixel_array_src = image->getPixels();
	ofPixels pixel_array_dst = image->getPixels();
	ofColor pixel_color_src;
	ofColor pixel_color_dst;
	float sum[color_component_count];
	for (y = 0; y < image_height - 1; ++y)
	{
		for (x = 0; x < image_width - 1; ++x)
		{
			pixel_index_img_dst = (image_width * y + x) * color_component_count;
			pixel_index_img_src = (image_width * y + x) * color_component_count;
			pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);
			for (c = 0; c < color_component_count; ++c)
			{
				if (c == 3) {
					pixel_color_dst[c] = alpha;
				}
				else {
					pixel_color_dst[c] = pixel_color_src[c];
				}
			}
			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
	}
	image->setFromPixels(pixel_array_dst);
}

void Texture::inversionFilter(ofImage* image)
{
	image_width = image->getWidth();
	image_height = image->getHeight();
	const int color_component_count = 4;
	int x, y;
	int c;
	int pixel_index_img_src;
	int pixel_index_img_dst;
	ofPixels pixel_array_src = image->getPixels();
	ofPixels pixel_array_dst = image->getPixels();
	ofColor pixel_color_src;
	ofColor pixel_color_dst;
	for (y = 0; y < image_height - 1; ++y)
	{
		for (x = 0; x < image_width - 1; ++x)
		{
			pixel_index_img_dst = (image_width * y + x) * color_component_count;
			pixel_index_img_src = (image_width * y + x) * color_component_count;
			pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);
			
			pixel_color_dst[0] = 255 - pixel_color_src[0];
			pixel_color_dst[1] = 255 - pixel_color_src[1];
			pixel_color_dst[2] = 255 - pixel_color_src[2];
			
			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
	}
	image->setFromPixels(pixel_array_dst);
}

void Texture::proceduralTexture(ofImage* image) {
	image_width = image->getWidth();
	image_height = image->getHeight();
	const int color_component_count = 4;
	int x, y;
	int c;
	int pixel_index_img_src;
	int pixel_index_img_dst;
	ofPixels pixel_array_src = image->getPixels();
	ofPixels pixel_array_dst = image->getPixels();
	ofColor pixel_color_src;
	ofColor pixel_color_dst;
	int row = 0;
	for (y = 0; y < image_height - 1; ++y)
	{
		for (x = 0; x < image_width - 1; ++x)
		{
			pixel_index_img_dst = (image_width * y + x) * color_component_count;
			pixel_index_img_src = (image_width * y + x) * color_component_count;
			pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);

			pixel_color_dst[0] = 0;
			pixel_color_dst[1] = 0;
			pixel_color_dst[2] = 0;

			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
		row += 1;
		if (row >= 5) {
			row = 0;
			y += 5;
		}
	}
	int column = 0;
	for (x = 0; x < image_width - 1; ++x)
	{
		for (y = 0; y < image_height - 1; ++y)
		{
			pixel_index_img_dst = (image_width * y + x) * color_component_count;
			pixel_index_img_src = (image_width * y + x) * color_component_count;
			pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);

			pixel_color_dst[0] = 0;
			pixel_color_dst[1] = 0;
			pixel_color_dst[2] = 0;

			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
		column += 1;
		if (column >= 5) {
			column = 0;
			x += 5;
		}
	}
	image->setFromPixels(pixel_array_dst);
}