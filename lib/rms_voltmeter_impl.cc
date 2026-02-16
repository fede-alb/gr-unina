/* -*- c++ -*- */
/*
 * Copyright 2026 myself.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "rms_voltmeter_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace unina {

using input_type = float;
using output_type = float;
rms_voltmeter::sptr rms_voltmeter::make(int vlen)
{
    return gnuradio::make_block_sptr<rms_voltmeter_impl>(vlen);
}


/*
 * The private constructor
 */
rms_voltmeter_impl::rms_voltmeter_impl(int vlen)
    : gr::sync_decimator("rms_voltmeter",
                         gr::io_signature::make(
                             1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                         gr::io_signature::make(1 /* min outputs */,
                                                1 /*max outputs */,
                                                sizeof(output_type)),
                         vlen),
	d_vlen(vlen)
{
}

/*
 * Our virtual destructor.
 */
rms_voltmeter_impl::~rms_voltmeter_impl() {}

int rms_voltmeter_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

    // Do <+signal processing+>

    for (int i = 0; i < noutput_items; i++) {
        float sum_sq = 0;

        for (int j = 0; j < d_vlen; j++) {
            float sample = in[i * d_vlen + j];
            sum_sq += sample * sample; // Somma dei quadrati
        }

        out[i] = std::sqrt(sum_sq / d_vlen);
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace unina */
} /* namespace gr */
