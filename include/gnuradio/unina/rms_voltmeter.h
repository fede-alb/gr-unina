/* -*- c++ -*- */
/*
 * Copyright 2026 myself.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_UNINA_RMS_VOLTMETER_H
#define INCLUDED_UNINA_RMS_VOLTMETER_H

#include <gnuradio/sync_decimator.h>
#include <gnuradio/unina/api.h>

namespace gr {
namespace unina {

/*!
 * \brief <+description of block+>
 * \ingroup unina
 *
 */
class UNINA_API rms_voltmeter : virtual public gr::sync_decimator
{
public:
    typedef std::shared_ptr<rms_voltmeter> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of unina::rms_voltmeter.
     *
     * To avoid accidental use of raw pointers, unina::rms_voltmeter's
     * constructor is in a private implementation
     * class. unina::rms_voltmeter::make is the public interface for
     * creating new instances.
     */
    static sptr make(int vlen);
};

} // namespace unina
} // namespace gr

#endif /* INCLUDED_UNINA_RMS_VOLTMETER_H */
