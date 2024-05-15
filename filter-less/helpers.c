#include "helpers.h"

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    int r = 0;
    int g = 0;
    int b = 0;

    int gr_color = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;

            if (((r + g + b) / 3.0) + 0.5 >= ((r + g + b) / 3) + 1)
            {
                gr_color = ((r + g + b) / 3) + 1;
            }
            else
            {
                gr_color = (r + g + b) / 3.0;
            }

            image[i][j].rgbtRed = gr_color;
            image[i][j].rgbtGreen = gr_color;
            image[i][j].rgbtBlue = gr_color;
        }
    }
    return;
}

// Convert image to sepia
int newR = 0;
int newG = 0;
int newB = 0;
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            newR = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue);
            newG = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue);
            newB = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue);

            if (((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue)) + 0.5 > newR + 1)
            {
                newR += 1;
            }
            if (((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue)) + 0.5 > newG + 1)
            {
                newG += 1;
            }
            if (((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue)) + 0.5 > newB + 1)
            {
                newB += 1;
            }

            if (newR > 255)
            {
                newR = 255;
            }
            if (newG > 255)
            {
                newG = 255;
            }
            if (newB > 255)
            {
                newB = 255;
            }

            image[i][j].rgbtRed = newR;
            image[i][j].rgbtGreen = newG;
            image[i][j].rgbtBlue = newB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int reflection = 0;
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            reflection = width - 1;
            swap(&image[j][i], &image[j][reflection - i]);
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avgnum = 0;
    double r = 0;
    double g = 0;
    double b = 0;
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (j + k < 0 || j + k >= width || i + l < 0 || i + l >= height)
                    {
                        continue;
                    }
                    r += copy[i + l][j + k].rgbtRed;
                    g += copy[i + l][j + k].rgbtGreen;
                    b += copy[i + l][j + k].rgbtBlue;
                    avgnum += 1;
                }
            }
            if ((r / avgnum) + 0.5 >= (int) ((r / avgnum)) + 1)
            {
                image[i][j].rgbtRed = (r / avgnum) + 1;
            }
            else
            {
                image[i][j].rgbtRed = r / avgnum;
            }
            if ((g / avgnum) + 0.5 >= (int) ((g / avgnum)) + 1)
            {
                image[i][j].rgbtGreen = (g / avgnum) + 1;
            }
            else
            {
                image[i][j].rgbtGreen = g / avgnum;
            }
            if ((b / avgnum) + 0.5 >= (int) ((b / avgnum)) + 1)
            {
                image[i][j].rgbtBlue = (b / avgnum) + 1;
            }
            else
            {
                image[i][j].rgbtBlue = b / avgnum;
            }

            avgnum = 0;
            r = 0;
            g = 0;
            b = 0;
        }
    }
    return;
}
