typedef struct {
    float x;
    float y;
} Point_t;

typedef struct {
    Point_t center;
    float radius;
} Circle_t;

/// Calculate the point that is at the intersection of all 4 circles.
Point_t calculate_point(Circle_t[4]);


/// Get the intersection point(s) between two circles.
int circle_intersection(Circle_t, Circle_t, Point_t *, Point_t *);
