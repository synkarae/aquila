/*
 *   Copyright 2016 Robert C. Taylor
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
/**
 * @file NuttallWindow.h
 *
 * Nuttall window.
 *
 * @package Quasar
 * @version 4.0.0-dev
 * @author Zbigniew Siciarz, Robert C. Taylor
 * @date 2007-2016
 * @since 3.0.0
 */

#ifndef QUASAR_SOURCE_WINDOW_NUTTALWINDOW_H
#define QUASAR_SOURCE_WINDOW_NUTTALWINDOW_H

#include "../../global.h"
#include "../SignalSource.h"
#include <cstddef>

namespace Quasar
{
    /**
     * Nuttall window.
     */
	SignalSourceTemplateMod(DataType Cos(DataType) = &std::cos)
    class NuttallWindow : public SignalSourceType
    {
    public:
        /**
         * Creates Nuttall window of given size.
         *
         * @param size window length
         */
        NuttallWindow(std::size_t size):
            SignalSourceType::SignalSource()
        {
            this->m_data.reserve(size);
            for (std::size_t n = 0; n < size; ++n)
            {
                this->m_data.push_back(
                    0.355768 - 0.487396 * Cos(2.0 * M_PI * n / static_cast<DataType>(size - 1)) +
                        0.144232 * Cos(4.0 * M_PI * n / static_cast<DataType>(size - 1)) -
                        0.012604 * Cos(6.0 * M_PI * n / static_cast<DataType>(size - 1))
                );
            }
        }
    };
}

#endif // QUASAR_SOURCE_WINDOW_NUTTALWINDOW_H
