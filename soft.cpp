#include<stdio.h>
#include <graphics.h>

void graph(int w1, int w2, int b, int n){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midx = getmaxx()/2;
    int midy = getmaxy()/2;

    line(0, midy, getmaxx(), midy);
    line(midx, 0, midx, getmaxy());

    int scale = 50;

    if(n == 1){
        int x[4][2] = {{0,0},{0,1},{1,0},{1,1}};
        int t[4] = {0,1,1,1};

        for(int i=0;i<4;i++){
            int px = midx + x[i][0]*scale;
            int py = midy - x[i][1]*scale;

            if(t[i]==1) setcolor(GREEN);
            else setcolor(RED);

            circle(px, py, 5);
        }
    }
    else{
        int x[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
        int t[4] = {-1,1,1,1};

        for(int i=0;i<4;i++){
            int px = midx + x[i][0]*scale;
            int py = midy - x[i][1]*scale;

            if(t[i]==1) setcolor(GREEN);
            else setcolor(RED);

            circle(px, py, 5);
        }
    }

    setcolor(YELLOW);

    if(w2 != 0){
        int x1 = -5, x2 = 5;

        int y1 = (-b - w1*x1)/w2;
        int y2 = (-b - w1*x2)/w2;

        int px1 = midx + x1*scale;
        int py1 = midy - y1*scale;

        int px2 = midx + x2*scale;
        int py2 = midy - y2*scale;

        line(px1, py1, px2, py2);
    }

    getch();
    closegraph();
}

/* activation function */
int activation(int yin,float theta){
    if(yin >= theta)
    return 1;
else
    return 0;
}

// activation 2
int activation2(int yin,float theta){
    if(yin >= theta)
    return 1;
else
    return -1;  
}

/* binary inputs */
int bin(int alpha, int n,float theta){
    int x[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    int t[4];
    
    if(n == 1){
        t[0]=0; t[1]=1; t[2]=1; t[3]=1;
    }
    else{
        t[0]=-1; t[1]=1; t[2]=1; t[3]=1;
    }

    int w1=0, w2=0, b=0 ,dw1,dw2,db;
    int epo;

    printf("\nEnter epochs :- ");
    scanf("%d",&epo);

    for(int e=0;e<epo;e++){
    	printf("\n\nEpoch = %d",e+1);
    	
    	printf("\nX1  X2  t  Yin  Y  dW1  dW2  dB  W1  W2  b");
        for(int i=0;i<4;i++){

            int yin = b + x[i][0]*w1 + x[i][1]*w2;
            int y;

            if(n == 1)
             y = activation(yin, theta);     // for {0,1}
        else
             y = activation2(yin, theta);
            
            
            dw1=0;
			dw2=0;
			db=0;


            if(y != t[i]){
                dw1 = alpha * t[i] * x[i][0];
                dw2 = alpha * t[i] * x[i][1];
                db  = alpha * t[i];

                w1 = w1 + dw1;
                w2 = w2 + dw2;
                b  = b  + db;
            }
            
            printf("\n%d   %d   %d   %d   %d   %d   %d    %d   %d   %d   %d", 
                    x[i][0], x[i][1], t[i], yin, y, dw1, dw2, db, w1,w2,b); }
    }
    printf("\nFinal Weights: w1=%d w2=%d bias=%d\n", w1,w2,b);
    
    graph(w1, w2, b, n);
    return 0;
}

/* bipolar inputs and targets */
int bipol(int alpha,float theta){
    int x[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    int t[4] = {-1,1,1,1};

    int w1=0, w2=0, b=0,dw1,dw2,db;
    int epo;

    printf("\nEnter epochs :- ");
    scanf("%d",&epo);

    for(int e=0;e<epo;e++){
    printf("\n\nEpoch = %d",e+1);

        printf("\nX1  X2  t  Yin  Y  dW1  dW2  dB  W1  W2  b");
        for(int i=0;i<4;i++){
            int yin = b + x[i][0]*w1 + x[i][1]*w2;
            int y = activation2(yin,theta);


        dw1=0;
		dw2=0;
		db=0;

		if(y != t[i]){
                dw1 = alpha * t[i] * x[i][0];
                dw2 = alpha * t[i] * x[i][1];
                db  = alpha * t[i];

                w1 = w1 + dw1;
                w2 = w2 + dw2;
                b  = b  + db;
            }

            printf("\n%d   %d   %d   %d   %d   %d   %d    %d   %d   %d   %d", 
                    x[i][0], x[i][1], t[i], yin, y, dw1, dw2, db, w1,w2,b); }
    }
    printf("\nFinal Weights: w1=%d w2=%d bias=%d\n", w1,w2,b);
    graph(w1, w2, b, 3);
    return 0;
}

int main(){
    int n, alpha;
    float theta;

    printf("\nEnter 1 for binary inputs and targets\n");
    printf("Enter 2 for binary inputs and bipolar targets\n");
    printf("Enter 3 for bipolar inputs and targets\n");
    scanf("%d",&n);

    printf("\nEnter learning factor :- ");
    scanf("%d",&alpha);
    
    printf("\nEnter theta :- ");
    scanf("%f",&theta);
    
    switch(n){
        case 1:
            bin(alpha,1,theta);
            break;

        case 2:
            bin(alpha,2,theta);
            break;

        case 3:
            bipol(alpha,theta);
            break;


        case 4:
            printf("\n---------Program ends---------\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}