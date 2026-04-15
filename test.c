#include<stdio.h>
#include <graphics.h>

void graph(float w1, float w2, float b){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midx = getmaxx()/2;
    int midy = getmaxy()/2;

    line(0, midy, getmaxx(), midy);
    line(midx, 0, midx, getmaxy());

    int scale = 50;

    // Removed n (it was undefined)
    int x[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    int t[4] = {-1,1,1,1};

    for(int i=0;i<4;i++){
        int px = midx + x[i][0]*scale;
        int py = midy - x[i][1]*scale;

        if(t[i]==1) setcolor(GREEN);
        else setcolor(RED);

        circle(px, py, 5);
    }

    setcolor(YELLOW);

    if(w2 != 0){
        float x1 = -5, x2 = 5;

        float y1 = (-b - w1*x1)/w2;
        float y2 = (-b - w1*x2)/w2;

        int px1 = midx + x1*scale;
        int py1 = midy - y1*scale;

        int px2 = midx + x2*scale;
        int py2 = midy - y2*scale;

        line(px1, py1, px2, py2);
    }

    getch();
    closegraph();
}

/* bipolar inputs and targets */
int bipol(float alpha,int theta){
    int x[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    int t[4] = {-1,1,1,1};

    float w1=0, w2=0, b=0,dw1,dw2,db,yin;
    int epo;

    printf("\nEnter epochs :- ");
    scanf("%d",&epo);

    for(int e=0;e<epo;e++){
        printf("\nX1  X2  t  Yin  dW1  dW2  dB  W1  W2  b");

        for(int i=0;i<4;i++){
            yin = b + x[i][0]*w1 + x[i][1]*w2;

            dw1 = alpha * (t[i] - yin) * x[i][0];
            dw2 = alpha * (t[i] - yin) * x[i][1];
            db  = alpha * (t[i] - yin);

            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b  = b  + db;

            printf("\n%d   %d   %d   %.2f   %.2f   %.2f   %.2f   %.2f   %.2f   %.2f", 
                    x[i][0], x[i][1], t[i], yin, dw1, dw2, db, w1,w2,b);
        }
    }

    printf("\nFinal Weights: w1=%.2f w2=%.2f bias=%.2f\n", w1,w2,b);
    graph(w1, w2, b);
    return 0;
}

int main(){
    float alpha;
    int theta;

    printf("\nEnter learning factor :- ");
    scanf("%f",&alpha);
    
    printf("\nEnter theta :- ");
    scanf("%d",&theta);
    
    bipol(alpha,theta);

    return 0;
}