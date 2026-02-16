/* -*- c++ -*- */
/*
 * Copyright 2026 Fede.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "my_amplifier_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace unina {

using input_type = float;
using output_type = float;
my_amplifier::sptr my_amplifier::make(float gain)
{
    return gnuradio::make_block_sptr<my_amplifier_impl>(gain);
}


/*
 * The private constructor
 */
my_amplifier_impl::my_amplifier_impl(float gain)
    : gr::sync_block("my_amplifier",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
	d_gain(gain)
{
}

/*
 * Our virtual destructor.
 */
my_amplifier_impl::~my_amplifier_impl() {}

int my_amplifier_impl::work(int noutput_items,
                            gr_vector_const_void_star& input_items,
                            gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

    // Do <+signal processing+>
	for(int i = 0; i < noutput_items; i++) {
		out[i] = in[i] * d_gain;
	}
    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace unina */
} /* namespace gr */
