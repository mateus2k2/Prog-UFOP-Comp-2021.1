

int main() {
    float a=1.0, b=-2.0, c=1.0;
    float d, r1, r2;

    d=b*b-4*a*c;
    r1=(-b+sqrt(d))/(2*a);
    r2=(-b-sqrt(d))/(2*a);

    printf("%f e %f",r1,r2);

    return 0;
}