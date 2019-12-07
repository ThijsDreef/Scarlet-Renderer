class Vector3F {
public:
    float x,y,z;

    float length();
    float dot(Vector3F other);
    void normalize();
    Vector3F unit();
    Vector3F cross(Vector3F other);

    Vector3F operator/(float scalar);
    Vector3F operator+(float add);
    Vector3F operator-(float min);
    Vector3F operator*(float scalar);
    Vector3F operator-();
    Vector3F operator/(Vector3F scalar);
    Vector3F operator+(Vector3F add);
    Vector3F operator-(Vector3F min);
    Vector3F operator*(Vector3F scalar);
    void operator/=(float scalar);   
    void operator+=(float add);
    void operator-=(float min);
    void operator*=(float scalar);

    Vector3F();
    Vector3F(float x, float y, float z);
    ~Vector3F();
};