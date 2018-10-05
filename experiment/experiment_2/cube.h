//
// Created by 刘元林 on 2018/9/26.
//

#ifndef EXPERIMENT_2_CUBE_H
#define EXPERIMENT_2_CUBE_H


class Box {
public:
    Box(int length,int width,int high);
    ~Box();
    int volume(Box *box);
    int SurfaceArea(Box *box);
    void change(int &length,int &width,int &high);
//    void change(int length,int width,int high);
    void change(int *length,int *width,int *high);
private:
    int length;
    int width;
    int high;
};


/**
 * 构造函数
 * @tparam T
 */
Box::Box(int length,int width,int high):
        length(length),width(width),high(high) {}

/**
 * 析构函数
 * @tparam T
 */
Box::~Box() {
//    destory();
}

int Box::volume(Box *box) {
    return (box->high)*(box ->length)*(box->width);
}

int Box::SurfaceArea(Box *box) {
    return (box->length*box->width+box->width*box->high+box->high*box->length)*2;
}

//void Box::change(int l, int w, int h) {
//    length = l;
//    width = w;
//    high = h;
//}
void Box::change(int &l, int &w, int &h) {
    length = l;
    width = w;
    high = h;
}
void Box::change(int *l, int *w, int *h) {
    length = *l;
    width = *w;
    high = *h;
}
#endif //EXPERIMENT_2_CUBE_H
