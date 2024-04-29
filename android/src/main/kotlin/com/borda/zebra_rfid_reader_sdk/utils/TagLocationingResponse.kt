package com.borda.zebra_rfid_reader_sdk.utils

import com.google.gson.Gson

object TagLocationingResponse {
    private var tag: String? = null
    private var distancePercent: Int? = null


    fun setTag(tag: String?) {
        this.tag = tag
    }

    fun getTag(): String? {
        return tag
    }

    fun setDistancePercent(distancePercent: Int?) {
        this.distancePercent = distancePercent
    }

    fun toJson(): String {
        return Gson().toJson(LocationInfo(tag, distancePercent))
    }

}