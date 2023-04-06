#include "FPToolkit.c"

int S_WIDTH, S_HEIGHT, SELECT;
int GRID = 10;
double POINT[1000];


// moves click onto grid
void adjust(double point[]) {
  for(int i = 0; i < 2; i++) {
    point[i] = round(point[i]/GRID)*GRID;
  }
}


// sorts the x values from lowest to highest
void sorting(double x[], int n) {
    int i, j;
    double temp;
    for (i = 1; i < n; i++) {
        temp = x[i];
        j = i - 1;
        while (j >= 0 && x[j] > temp) {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = temp;
    }
}


// accepts points and connects lines until clicking bottom of screen
int shape(double x[], double y[]) {
  int n;
  double p[2];
  G_fill_rectangle(0, 0, S_WIDTH, 20);
  G_wait_click(p);
  adjust(p);
  G_fill_circle(p[0], p[1], 2);
  
  while(p[1] > 20) {
    x[n] = p[0];
    y[n] = p[1];
    if(n > 0) {
      G_line(x[n-1], y[n-1], x[n], y[n]);
    }
    n++;
    G_wait_click(p);
    adjust(p);
    G_fill_circle(p[0], p[1], 2);
  }

  if(n >= 1) {
    G_line(x[0], y[0], x[n-1], y[n-1]);
  }
  x[n] = x[0];
  y[n] = y[0];
  return n;
}

// checks if the height is between the y values of two points
Bool inside(double y1, double y2, double link) {
  if(y1 < y2) {
    if(y1 <= link && link <= y2) {
      return True;
    }
  } else {
    if(y2 <= link && link <= y1) {
      return True;
    }
  }
  return False;
}


// finds the x-values of intersections and plots a circle at it
double intersect(double x1, double y1, double x2, double y2, int i){
  double xCoord, yCoord, m, b;
  yCoord = i;
  if(x1 != x2) {
    m = (y2-y1)/(x2-x1);
    b = y1 - m*x1;
    xCoord = (yCoord -b)/m;
  } else {
    xCoord = x1;
  }
  G_rgb(1,0,0);
  G_rgb(0,1,0);
  return xCoord;
}


// draws a line from x-intersect to next x-intersect at same height
void draw(double X[], double pix, int num) {
  if(num != 0 && num != 1) {
    for(int i = 0; i < num - 1; i+=2) {
      G_line(X[i], pix, X[i+1], pix);
      // comment out this wait key to instant fill
      G_wait_key();
    }
  }
}


// main function that fills the object
void fill(double xp[], double yp[], int count){
  for(double yPixel = 0.1; yPixel < S_HEIGHT; yPixel++){
    double xVals[count];
    int num = 0;
    for(int start =0; start < count; start++){
      int end = (start+1)%count;
      if(inside(yp[start],yp[end], yPixel)){
	xVals[num++] = intersect(xp[start], yp[start], xp[end], yp[end], yPixel);
      }
    }
    sorting(xVals, num);
    draw(xVals, yPixel, num);
  }
}


int main() {
  double xValues[1000];
  double yValues[1000];
  int count;

  S_WIDTH = 800; S_HEIGHT = 800;
  G_init_graphics(S_WIDTH, S_HEIGHT);
  G_rgb(0, 0, 0);
  G_clear();

  G_rgb(0, 0.2, 0);
  for(int i = 0; i < 800; i+=GRID) {
    G_line(i, 0, i, S_HEIGHT-1);
    G_line(0, i, S_WIDTH-1, i);
  }

  G_rgb(1, 0, 0);
  count = shape(xValues, yValues);

  fill(xValues, yValues, count);

  G_wait_key();
}
