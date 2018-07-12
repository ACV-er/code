#include<stdio.h>
int main(void) {
    printf("1 2\n2 3\n3 5\n4 7\n5 23\n6 29\n7 31\n8 37\n9 53\n10 59\n11 71\n12 73\n13 79\n14 233\n15 239\n16 293\n17 311\n18 313\n19 317\n20 373\n21 379\n22 593\n23 599\n24 719\n25 733\n26 739\n27 797\n28 2333\n29 2339\n30 2393\n31 2399\n32 2939\n33 3119\n34 3137\n35 3733\n36 3739\n37 3793\n38 3797\n39 5939\n40 7193\n41 7331\n42 7333\n43 7393\n44 23333\n45 23339\n46 23399\n47 23993\n48 29399\n49 31193\n50 31379\n51 37337\n52 37339\n53 37397\n54 59393\n55 59399\n56 71933\n57 73331\n58 73939\n59 233993\n60 239933\n61 293999\n62 373379\n63 373393\n64 593933\n65 593993\n66 719333\n67 739391\n68 739393\n69 739397\n70 739399\n71 2339933\n72 2399333\n73 2939999\n74 3733799\n75 5939333\n76 7393913\n77 7393931\n78 7393933\n79 23399339\n80 29399999\n81 37337999\n82 59393339\n83 73939133\n");

    return 0;
}
/*#include<stdbool.h>

int prim[9592];

bool isprim(int m) {
//    printf("2");
    if(m==1 || m==0) return false;
    int i;
    for(i=0; prim[i]*prim[i]<=m && i<9592; i++) {
        if(m%prim[i] == 0) {
            return false;
        }
    }
    return true;
}

bool is(int m) {
//    printf("1");
    while(m) {
        if( isprim(m) ) {
            m /= 10;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void getprim(void) {
    bool num[100000]={true, true, false};
    int i, j, cnt=0;
    for(i=0; i<1000; i++) {
        if(num[i] == false) {
            prim[cnt++] = i;
            for(j=i*i; j<100000; j+=i) {
                num[j] = true;
            }
        }
    }
    for(i=1000; i<100000; i++) {
        if(num[i] == false) {
            prim[cnt++] = i;
        }
    }
//    printf("%d", cnt);
    return;
}

int main(void) {
    int cnt=2;
    getprim();
    int i;
 //   for(i=0; i<1681; i++) {
 //       printf("%8d", prim[i]);
 //   }
 //   getchar();
    printf("1 2\\n");
    for(i=3; i<=2147483647 && cnt<84; i+=2) {
        if( is(i) ) {
            printf("%d %d\\n",cnt++, i);
        }
    }


    return 0;
}*/

