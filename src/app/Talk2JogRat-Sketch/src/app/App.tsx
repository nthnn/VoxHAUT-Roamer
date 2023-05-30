import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import $ from "jquery";

import LoadingScreen from './LoadingScreen';
import SplashScreen from './SplashScreen';

let root = ReactDOMClient.createRoot(document.getElementById('main'));
root.render(<SplashScreen />);

class App {
    constructor() { }

    main(): void {
        setTimeout(()=> {
            let splashScreen: any = $("#splash-screen");
            splashScreen.addClass("animate__fadeOut");

            setTimeout(()=> {
                splashScreen.addClass("d-none");
                this.loadScreen();
            }, 1200);
        }, 3000);
    }

    loadScreen(): void {
        root.render(<LoadingScreen />);
    }
}

const application = new App();
application.main();