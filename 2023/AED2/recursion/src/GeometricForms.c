#include "GeometricForms.h"
#include <unistd.h>
#include <math.h>

#define RADIUS (double)(((WIDTH + HEIGHT) / 6) + ((WIDTH + HEIGHT) / 24)) // Radius of the circle
#define CENTER (double)((WIDTH / 2) + (HEIGHT / 2)) / 2 // Center of the window

void drawCircle(double, double, double); // Draws a circle
void drawSquare(int, int, int, int); // Draws a square
void drawAllCircles(double, double, double, unsigned); // Draws all the circles
void drawAllSquares(int, int, int, int, int, unsigned); // Draws all the squares

// Draws a circle
void drawCircle(double x, double y, double radius) {
    gfx_set_color(255, 255, 255); // White
    gfx_ellipse(x, y, radius, radius);
}

// Draws a square
void drawSquare(int xi, int yi, int xf, int yf) {
    gfx_set_color(0, 0, 0); // Black
    gfx_filled_rectangle(xi, yi, xf, yf);
    gfx_set_color(255, 255, 255); // White
    gfx_rectangle(xi, yi, xf, yf);
}

// Draws all the circles
void drawAllCircles(double centerX, double centerY, double radius, unsigned recursionLevel) {
    drawCircle(centerX, centerY, radius);

    if (recursionLevel != 0) {
        double newRadius = (radius / 2); // New radius
        double newCenter = (radius / sqrt(8)); // New center    
        drawAllCircles(centerX - newCenter, centerY - newCenter, newRadius, recursionLevel - 1); // Top left
        drawAllCircles(centerX + newCenter, centerY - newCenter, newRadius, recursionLevel - 1); // Top right
        drawAllCircles(centerX - newCenter, centerY + newCenter, newRadius, recursionLevel - 1); // Bottom left
        drawAllCircles(centerX + newCenter, centerY + newCenter, newRadius, recursionLevel - 1); // Bottom right
    }
}

// Draws all the squares
void drawAllSquares(int xi, int yi, int xf, int yf, int side, unsigned recursionLevel) {
    if (recursionLevel != 0) {
        drawAllSquares(xi + (side / 4), yi - (side / 2), xf - (side / 4), yf - side, side / 2, recursionLevel - 1); // Top
        drawAllSquares(xi + (side / 4), yi + side, xf - (side / 4), yf + (side / 2), side / 2, recursionLevel - 1); // Bottom
        drawAllSquares(xi - (side / 2), yi + (side / 4), xf - side, yf - (side / 4), side / 2, recursionLevel - 1); // Left
        drawAllSquares(xi + side, yi + (side / 4), xf + (side / 2), yf - (side / 4), side / 2, recursionLevel - 1); // Right
    }

    drawSquare(xi, yi, xf, yf);
}

// Shows the recursive circles
void showRecursiveCircles(unsigned recursionLevel) {
    gfx_init(WIDTH, HEIGHT, "CIRCLES");

    drawAllCircles(CENTER, CENTER, RADIUS, recursionLevel);

    gfx_paint();
    sleep(10);
    gfx_quit();
}

// Shows the recursive squares
void showRecursiveSquares(unsigned recursionLevel) {
    gfx_init(WIDTH, HEIGHT, "SQUARES");

    drawAllSquares(WIDTH / 3, HEIGHT / 3, WIDTH / 3 + (WIDTH / 3), HEIGHT / 3 + (HEIGHT / 3), 200, recursionLevel);

    gfx_paint();
    sleep(10);
    gfx_quit();
}