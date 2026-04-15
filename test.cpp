#include<stdio.h>
#include<graphics.h>
#include<math.h>

float rmse[100];

// ----------- RMSE GRAPH -----------
void graph_rmse(float rmse[], int epo){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxy = getmaxy();

    // Axes
    line(50, 50, 50, maxy-50);                 // Y-axis
    line(50, maxy-50, getmaxx()-50, maxy-50);  // X-axis

    // Labels (optional but good for exam)
    outtextxy(20, 40, "RMSE");
    outtextxy(getmaxx()-100, maxy-30, "Epoch");

    int scale_x = 40;
    int scale_y = 200;

    for(int i=0;i<epo-1;i++){
        int x1 = 50 + i*scale_x;
        int y1 = (maxy-50) - rmse[i]*scale_y;

        int x2 = 50 + (i+1)*scale_x;
        int y2 = (maxy-50) - rmse[i+1]*scale_y;

        line(x1, y1, x2, y2);
        circle(x1, y1, 3);
    }

    getch();
    closegraph();
}

// ----------- ADALINE TRAINING -----------
void bipol(float alpha){
    int x[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    int t[4] = {-1,1,1,1};

    float w1=0, w2=0, b=0;
    float dw1, dw2, db, yin;

    int epo;

    printf("\nEnter epochs :- ");
    scanf("%d",&epo);

    for(int e=0;e<epo;e++){
        float sum_error = 0;

        printf("\n\nEpoch %d", e+1);
        printf("\nX1  X2  t  Yin   dW1   dW2   dB    W1    W2    b");

        for(int i=0;i<4;i++){
            yin = b + x[i][0]*w1 + x[i][1]*w2;

            float error = t[i] - yin;

            sum_error += error * error;

            dw1 = alpha * error * x[i][0];
            dw2 = alpha * error * x[i][1];
            db  = alpha * error;

            w1 += dw1;
            w2 += dw2;
            b  += db;

            printf("\n%d   %d   %d   %.2f   %.2f   %.2f   %.2f   %.2f   %.2f   %.2f",
                x[i][0], x[i][1], t[i], yin, dw1, dw2, db, w1, w2, b);
        }

        rmse[e] = sqrt(sum_error / 4.0);
        printf("\nRMSE = %.4f\n", rmse[e]);
    }

    printf("\nFinal Weights: w1=%.2f w2=%.2f bias=%.2f\n", w1,w2,b);

    // ONLY RMSE GRAPH
    graph_rmse(rmse, epo);
}

// ----------- MAIN -----------
int main(){
    float alpha;

    printf("\nEnter learning factor (recommended 0.1) :- ");
    scanf("%f",&alpha);

    bipol(alpha);

    return 0;
}