package com.borda.zebra_rfid_reader_sdk

import android.os.Handler
import android.os.Looper
import io.flutter.plugin.common.EventChannel
import io.flutter.plugin.common.EventChannel.EventSink


class TagDataEventHandler : EventChannel.StreamHandler {
    private var eventSink: EventSink? = null
    private val uiThreadHandler = Handler(Looper.getMainLooper())


    override fun onListen(arguments: Any?, events: EventSink?) {
        /// The Flutter app has opened the Event Channel
        eventSink = events
    }

    override fun onCancel(arguments: Any?) {
        /// The Flutter app has closed the Event Channel
        eventSink = null
    }

    fun sendEvent(json: String) {
        /// Send a message to the Flutter app
        if (eventSink != null) {
            uiThreadHandler.post { eventSink!!.success(json) }
        }
    }
}
