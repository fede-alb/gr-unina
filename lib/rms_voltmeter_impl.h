/* -*- c++ -*- */
/*
 * Copyright 2026 myself.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_UNINA_RMS_VOLTMETER_IMPL_H
#define INCLUDED_UNINA_RMS_VOLTMETER_IMPL_H

#include <gnuradio/unina/rms_voltmeter.h>

namespace gr {
namespace unina {

class rms_voltmeter_impl : public rms_voltmeter
{
private:
    // Nothing to declare in this block.
    int d_vlen;

public:
    rms_voltmeter_impl(int vlen);
    ~rms_voltmeter_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace unina
} // namespace gr

#endif /* INCLUDED_UNINA_RMS_VOLTMETER_IMPL_H */
