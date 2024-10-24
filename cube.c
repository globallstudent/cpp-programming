#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

// Cube properties
float A, B, C;
float cubeWidth = 10;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCHIICode = ' ';
int distanceFromCam = 60;
float K1 = 40; // Scaling factor for projection

float incrementSpeed = 0.6;
float x, y, z;
float ooz;
int xp, yp;
int idx;

// Function to calculate X position after rotation
float calculateX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + 
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

// Function to calculate Y position after rotation
float calculateY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) - j * sin(A) * sin(B) * sin(C) + 
           k * cos(A) * sin(B) * sin(C) - i * cos(B) * sin(C);
}

// Function to calculate Z position after rotation
float calculateZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

// Function to render a surface of the cube
void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = calculateX(cubeX, cubeY, cubeZ);
    y = calculateY(cubeX, cubeY, cubeZ);
    z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    ooz = 1 / z;

    // Projection to 2D screen coordinates
    xp = (int)(width / 2 + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    // Valid index check
    idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main() {
    // Clear the screen
    printf("\x1b[2J");

    while (1) {
        // Initialize the buffer and zBuffer for each frame
        memset(buffer, backgroundASCHIICode, width * height);
        memset(zBuffer, 0, width * height * sizeof(float));

        // Render all six cube faces
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                // Front and back faces
                calculateForSurface(cubeX, cubeY, -cubeWidth, '@'); // Back face
                calculateForSurface(cubeX, cubeY, cubeWidth, '#');  // Front face

                // Left and right faces
                calculateForSurface(-cubeWidth, cubeY, cubeX, '$'); // Left face
                calculateForSurface(cubeWidth, cubeY, cubeX, '%');  // Right face

                // Top and bottom faces
                calculateForSurface(cubeX, -cubeWidth, cubeY, '*'); // Bottom face
                calculateForSurface(cubeX, cubeWidth, cubeY, '+');  // Top face
            }
        }

        // Move the cursor to the top-left of the screen
        printf("\x1b[H");

        // Print the buffer
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);
        }

        // Increment the angles for rotation
        A += 0.04; // Rotation around X-axis
        B += 0.03; // Rotation around Y-axis
        C += 0.02; // Rotation around Z-axis

        usleep(30000); // Small delay for smoother animation
    }

    return 0;
}

