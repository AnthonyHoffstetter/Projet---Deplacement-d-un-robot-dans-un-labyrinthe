#ifndef ALGORITHME_H
#define ALGORITHME_H

class robot;
class terrain;

class algorithme
{
public:
    virtual ~algorithme()=default;
    virtual void executer(const robot &r, const terrain &t)=0;

};

#endif // ALGORITHME_H
