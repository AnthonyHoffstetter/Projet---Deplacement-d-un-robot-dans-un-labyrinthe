#ifndef FAKEOBSERVATEUR_H
#define FAKEOBSERVATEUR_H


class fakeObservateur : public observateur {
public:
    void update(const robot& r) override
    {}
};

#endif // FAKEOBSERVATEUR_H
