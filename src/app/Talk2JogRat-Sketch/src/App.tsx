import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';
import $ from "jquery";

import LoadingScreen from './LoadingScreen';
import SplashScreen from './SplashScreen';

let root = ReactDOMClient.createRoot(document.getElementById('main'));
root.render(<SplashScreen />);

setTimeout(()=> {
    let splashScreen: any = $("#splash-screen");
    splashScreen.addClass("animate__fadeOut");

    setTimeout(()=> {
        splashScreen.addClass("d-none");
        root.render(<LoadingScreen />);
    }, 1200);
}, 3000);