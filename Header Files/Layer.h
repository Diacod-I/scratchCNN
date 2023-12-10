#pragma once

#include <Eigen/Core>
#include <vector>
#include "RandomNum.h"
#include "config.h"
#include "Optimizer.h"

class Layer{
    protected:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;
        const int m_in_size;
        const int m_out_size;
    
    public:
        Layer(const int in_size, const int out_size);
            m_in_size(in_size),
            m_out_size(out_size){}

        virtual ~Layer();

        int in_size() const { return m_in_size; }
        int out_size() const { return m_out_size; }

        virtual void init(const Scalar& mu, const Scalar &sigma, RandomNum& rng) = 0;
        virtual void forward(const Matrix& prev_layer_output) = 0;

        virtual const Matrix& output() const = 0;

        virtual void backprop(const Matrix& prev_layer_output, const Matrix& next_layer_data) = 0;
        virtual const Matrix& backprop() const=0;

        virtual std::vector<Scalar> get_parameter() const = 0;
        virtual void set_parameter(const std::vector<Scalar>& param) {}
        virtual std::vector<Scalar> get_derivatives() const = 0; 

    private:

};

Layer::Layer(){

}

Layer::~Layer(){

}