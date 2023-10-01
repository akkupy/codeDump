#include<iostream>
using namespace std;

class Area{
    private:
        int side;
        int length;
        int breadth;
        double radius;
    public:
        Area(int side=1,int length=1,int breadth=1,double radius=1){
            this->side=side;
            this->length=length;
            this->breadth=breadth;
            this->radius=radius;
        }
        inline int Square()
        {
           return side*side;
        }
        inline int Rectangle()
        {
            return length*breadth;
        }
        inline double Circle()
        {
            return 3.14*radius*radius;
        }

        friend int Return_Square(Area);
        friend int Return_Rectangle(Area );
        friend int Return_Circle(Area );
};

int Return_Square(Area a)
{
    return a.side;
}

int Return_Rectangle(Area a)
{
    return a.Rectangle();
}

int Return_Circle(Area a)
{
    return a.radius;
}

class Volume{
    private:
        int height;
    public:
    int x;
        Volume(int height=1){
            this->height=height;
        }
        inline int Cube(Area a)
        {
            x=Return_Square(a);
            return x*x*x;
        }
        inline int Cuboid(Area a)
        {   
            x=Return_Rectangle(a);
            return x*height;
        }
        inline double Sphere(Area a)
        {
           x=Return_Circle(a);
           return (1.3333)*3.14*x*x*x;
        }

};

void Menu_driven_function(Area x,Volume y)
{
    int t=1,k,s,l,b,h,r;
    while(t)
   {
    cout<<"\n1. Area of a Square      - ENTER 1\n";
    cout<<"2. Area of a Rectangle   - ENTER 2\n";
    cout<<"3. Area of a Circle      - ENTER 3\n";
    cout<<"4. Volume of a Cube      - ENTER 4\n";
    cout<<"5. Volume of a Cuboid    - ENTER 5\n";
    cout<<"6. Volume of Sphere      - ENTER 6\n";
    cout<<"7. Compare Cube          - ENTER 7\n";
    cout<<"8. Compare Cuboids       - ENTER 8\n";
    cout<<"9. Compare Spheres       - ENTER 9\n";
    cout<<"10. Exit                 - ENTER 10\n";
    cin>>k;

    switch(k){
        case 1:cout<<x.Square()<<endl;       break;
        case 2:cout<<x.Rectangle()<<endl;      break;
        case 3:cout<<x.Circle()<<endl;      break;
        case 4:cout<<y.Cube(x)<<endl;      break;
        case 5:cout<<y.Cuboid(x)<<endl;      break;
        case 6:cout<<y.Sphere(x)<<endl;      break;
        case 7:{
            cout<<"Enter the measurements of another Cube to compare: ";
            cout<<"Enter side: ";       cin>>s;
            Area x1(s);
            Volume y1;
            if(y1.Cube(x1)>y.Cube(x))
            {
                cout<<"THE 2nd CUBE HAS GREATER VOLUME\n";
            }else if(y1.Cube(x1)<y.Cube(x))
            {
                cout<<"THE 1st CUBE HAS GREATER VOLUME\n";
            }else{
                cout<<"BOTH THE CUBES HAS SAME VOLUME\n";
            }
            break;
        }
        case 8:
        {
            cout<<"Enter the measurements of another Cuboid to compare: ";
            cout<<"Enter length: ";     cin>>l;
            cout<<"Enter breadth: ";    cin>>b;
            cout<<"Enter hight: ";      cin>>h; 
            Area x1(1,l,b);
            Volume y1(h);
            if(y1.Cuboid(x1)>y.Cuboid(x))
            {
                cout<<"THE 2nd CUBOID HAS GREATER VOLUME\n";
            }else if(y1.Cuboid(x1)<y.Cuboid(x))
            {
                cout<<"THE 1st CUBOID HAS GREATER VOLUME\n";
            }else{
                cout<<"BOTH THE CUBOIDS HAS SAME VOLUME\n";
            }
            break;
        }
        case 9:
        {
            cout<<"Enter the RADIUS of another Sphere to compare: ";
            cout<<"Enter radius: ";     cin>>r; 
            Area x1(1,1,1,r);
            Volume y1;
            if(y1.Sphere(x1)>y.Sphere(x))
            {
                cout<<"THE 2nd SPHERE HAS GREATER VOLUME\n";
            }else if(y1.Sphere(x1)<y.Sphere(x))
            {
                cout<<"THE 1st SPHERE HAS GREATER VOLUME\n";
            }else{
                cout<<"BOTH THE SPHERES HAS SAME VOLUME\n";
            }
            break;
        }
        case 10: t=0;
    }
   }
}

int main()
{
    int s,l,b,h,r,flag;
    
   
   cout<<"TO ENTER THE MEASUREMENTS     - ENTER 1\n";
   cout<<"ELSE                          - ENTER 0\n";
   cin>>flag;
   if(flag){
        cout<<"Enter side: ";       cin>>s;
        cout<<"Enter length: ";     cin>>l;
        cout<<"Enter breadth: ";    cin>>b;
        cout<<"Enter hight: ";      cin>>h;
        cout<<"Enter radius: ";     cin>>r; 
        Area x(s,l,b,r);
        Volume y(h);
        Menu_driven_function( x,y);
   }else{
        Area x;
        Volume y;
        Menu_driven_function( x,y);
   }


    return 0;
}