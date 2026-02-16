/* -*- c++ -*- */
/*
 * Copyright 2026 Fede.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_UNINA_MY_AMPLIFIER_H
#define INCLUDED_UNINA_MY_AMPLIFIER_H

#include <gnuradio/sync_block.h>
#include <gnuradio/unina/api.h>

namespace gr {
namespace unina {

/*!
 * \brief <+description of block+>
 * \ingroup unina
 *
 */
class UNINA_API my_amplifier : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<my_amplifier> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of unina::my_amplifier.
     *
     * To avoid accidental use of raw pointers, unina::my_amplifier's
     * constructor is in a private implementation
     * class. unina::my_amplifier::make is the public interface for
     * creating new instances.
     */
    static sptr make(float gain);
};

} // namespace unina
} // namespace gr

#endif /* INCLUDED_UNINA_MY_AMPLIFIER_H */
