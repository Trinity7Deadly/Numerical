#include "FPToolkit.c"

int drawLine(double x[], double y[], int n){
  G_rgb(1,0,0);
  for(double t; t < 800; t++){
    double yt = 0;
    for(int i = 0; i < n; i++){
      double tempy = y[i];
      for(int j = 0; j < n; j++){
	if(j != i){
	  tempy *= (t - x[j]) / (x[i] - x[j]) ;
	  
	}
	
      }
      yt += tempy; 

    }
      G_fill_circle(t, yt, 1);
    
    }

    return 1;
    

}

int clickandsave(double x[], double y[])
{
  double xp,yp,p[2] ;
  int numpoints ;

  G_rgb(1, 0, 0) ; // red
  G_fill_rectangle(0,0 ,30,30) ;

  G_rgb(0.5,0.5,0.5) ;
  numpoints = 0 ;
  while (0 == 0) {

     G_wait_click(p) ;
     xp = p[0] ; yp = p[1] ;

     if ((xp >= 0) && (xp <= 30) && 
         (yp >= 0) && (yp <= 30))  { break ; }

     G_fill_rectangle(xp-2, yp-2, 4,4) ;     

     x[numpoints] = xp ; y[numpoints] = yp ; numpoints++ ;

  }

  return numpoints ;
}



int main()
{
  double x[100],y[100] ;
  int n,i ;
  double xb,yb,numer,denom,m ;

  G_init_graphics(800,800) ;
  G_rgb(0,0,0) ; G_clear() ;

  n = clickandsave(x,y) ;

  for(int i = 0; i < n; i++){
    printf("%lf %lf \n", x[i], y[i]);
  }

  //G_rgb(1,1,0) ;
  //G_fill_polygon(x,y,n) ;

  drawLine(x, y, n);

  G_wait_key() ;
}
