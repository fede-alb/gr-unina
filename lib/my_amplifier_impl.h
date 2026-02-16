/* -*- c++ -*- */
/*
 * Copyright 2026 Fede.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_UNINA_MY_AMPLIFIER_IMPL_H
#define INCLUDED_UNINA_MY_AMPLIFIER_IMPL_H

#include <gnuradio/unina/my_amplifier.h>

namespace gr {
namespace unina {

class my_amplifier_impl : public my_amplifier
{
private:
    // Nothing to declare in this block.
    float d_gain;

public:
    my_amplifier_impl(float gain);
    ~my_amplifier_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace unina
} // namespace gr

#endif /* INCLUDED_UNINA_MY_AMPLIFIER_IMPL_H */
