/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pinctrl.h
 * Author: justas
 *
 * Created on August 7, 2016, 1:02 PM
 */

#ifndef PINCTRL_H
#define PINCTRL_H

class Pinctrl {
public:
    Pinctrl();
    virtual ~Pinctrl();
    void init_pins();
    void write_pin(int pin, int state);
private:

};

#endif /* PINCTRL_H */

