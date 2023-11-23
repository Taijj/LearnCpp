
class Matrix
{
    Matrix operator+(const Matrix &rhs) const // Won't change initial object
    {
        return Matrix();
    }

    Matrix operator-=(const Matrix &rhs) // For changing initial object
    {
        return Matrix();
    }

    // etc
};
