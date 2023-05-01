#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include "FPToolkit.c"

complex eval(complex t[], int d, complex r, complex o[]){
  o[0]=0+0*I;
  for(int n = 1; n<d+1; n++){
    o[n] = t[n-1] + o[n-1]*r;
  }
  return o[d]*r + t[d];
}

int main(){
  
  double cr, ci, xcenter, ycenter, viewRad;
  double p1[2], p2[2] ;
  int d, check;
  complex c, val, der;
  printf("Degree: ");
  scanf("%d", &d);
  complex t[d+1];
  complex T[d+1];
  complex temp1[d+1];
  complex temp2[d+1];
  complex roots[d];
  for(int i = 0; i<d; i++){
    printf("Coefficient %d: ", d-i);
    scanf("%lf", &cr);
    T[i] = cr+0*I;
  }
  printf("Coefficient 0: ");
  scanf("%lf", &cr);
  T[d] = cr+0*I;
  printf("Center of view and radius (x y r): ");
  scanf("%lf %lf %lf", &xcenter, &ycenter, &viewRad);
  
  for(int n = 0; n<d+1; n++){
      t[n]=T[n];
  }
  G_init_graphics(1000,1000);
  
  G_rgb(0,0,0);
  G_clear();
  
  for(int m = 0; m<d; m++){
    c = 2+1*I;
    for(int i = 0; i<300; i++){
    
      val = eval(t, d, c, temp1);
      der = eval(temp1,d,c,temp2);
      if(der == 0){
        c+=1*I;
        val = eval(t, d, c, temp1);
        der = eval(temp1,d,c,temp2);
      }
      
      c-= val/der;
    }
    
    printf("%20.16lf + %20.16lfi\n", creal(c), cimag(c));
    roots[m] = c;
    for(int n = 0; n<d+1; n++){
        t[n]=temp1[n];
    }
  }
  while(1){
    G_rgb(0,0,0);
    G_clear();
    for(int x = 0; x<1000; x++){
      for(int y = 0; y<1000; y++){
       c = ((x-500)*(viewRad/500)-xcenter)+((y-500)*(viewRad/500)-ycenter)*I;
       //printf("%lf + %lfi\n", creal(c), cimag(c));
       for(int i = 0; i<50; i++){
     
          val = eval(T, d, c, temp1);
          der = eval(temp1,d,c,temp2);
          if(der == 0){
            c+=.0001*I;
            val = eval(T, d, c, temp1);
            der = eval(temp1,d,c,temp2);
          } 
        
          c-= val/der;
        }
        //printf("%20.16lf + %20.16lfi\n", creal(c), cimag(c));
        for(int i = 0; i<d; i++){
          if(cabs(c-roots[i])<.001){
            //printf("%d\n", i);
            G_rgb(i*(1.0/d),1-i*(1.0/d), .8);
          }
        }
        G_point(x,y);
      }
    }
    G_rgb(1,0,0);
    G_fill_rectangle(0,0,30,30);
    G_wait_click(p1);
    if(p1[0]<30 && p1[1]<30) exit(0);
    xcenter = -((p1[0]-500)*(viewRad/500)-xcenter);
    ycenter = -((p1[1]-500)*(viewRad/500)-ycenter);
    printf("new center= %lf + %lfi\n", xcenter, ycenter);
    G_fill_circle(p1[0],p1[1],4);
    G_wait_click(p2);
    G_fill_circle(p2[0],p2[1],4);
    if(p2[0]<30 && p2[1]<30) exit(0);
    viewRad = sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]))*(viewRad/500)/sqrt(2.0);
    printf("new radius = %lf\n", viewRad);
  }
}
