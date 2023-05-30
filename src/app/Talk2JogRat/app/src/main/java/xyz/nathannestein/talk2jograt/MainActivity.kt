package xyz.nathannestein.talk2jograt

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.view.Window
import android.webkit.*
import android.widget.Toast

import androidx.webkit.WebViewAssetLoader;

class MainActivity : AppCompatActivity() {
    private var shouldExit: Boolean = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        this.requestWindowFeature(Window.FEATURE_NO_TITLE)
        this.setContentView(R.layout.activity_main)

        val webView: WebView = findViewById(R.id.main_web_view)
        val assetLoader = WebViewAssetLoader.Builder()
            .addPathHandler("/assets/", WebViewAssetLoader.AssetsPathHandler(this))
            .build()

        webView.webViewClient = LocalWebViewClient(assetLoader)
        webView.settings.allowContentAccess = true
        webView.settings.allowFileAccess = true
        webView.settings.allowUniversalAccessFromFileURLs = true
        webView.settings.allowFileAccessFromFileURLs = true
        webView.settings.javaScriptEnabled = true
        webView.webViewClient = LocalWebViewClient(assetLoader)

        webView.loadUrl("file:///android_asset/index.html")
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
    }
}