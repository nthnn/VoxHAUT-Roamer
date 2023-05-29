package xyz.nathannestein.talk2jograt

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.webkit.WebView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    private var shouldExit: Boolean = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val webView: WebView = findViewById(R.id.main_web_view)
        webView.settings.javaScriptEnabled = true
        webView.loadUrl("file://android_asset/index.html")
    }

    override fun onBackPressed() {
        when {
            this.shouldExit -> this.finish()
            else -> {
                Toast.makeText(this, "Press back again to exit.", Toast.LENGTH_SHORT).show()
                shouldExit = true

                Handler().postDelayed({
                    shouldExit = false
                }, 3000)
            }
        }
        this.finish()
    }
}