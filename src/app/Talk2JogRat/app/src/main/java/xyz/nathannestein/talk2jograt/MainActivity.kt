package xyz.nathannestein.talk2jograt

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.webkit.WebView;

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val webView: WebView = findViewById(R.id.main_web_view);
        webView.settings.javaScriptEnabled = true
    }
}