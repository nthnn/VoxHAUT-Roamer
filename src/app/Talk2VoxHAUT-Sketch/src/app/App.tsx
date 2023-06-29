import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import $ from "jquery";

import BubbleChat from './BubbleChat';
import FloatingCircleButton from './FloatingCircleButton';
import LoadingScreen from './LoadingScreen';
import SplashScreen from './SplashScreen';

class App {
    private root = ReactDOMClient.createRoot(document.getElementById('main'));
    private chats: Array<string[]>;

    constructor() {
        this.chats = [];
        this.root.render(<SplashScreen />);
    }

    main(): void {
        setTimeout(()=> {
            let splashScreen = $("#splash-screen");
            splashScreen.addClass("animate__fadeOut");

            setTimeout(()=> {
                splashScreen.addClass("d-none");
                this.loadScreen();
            }, 1200);
        }, 3000);
    }

    loadScreen(): void {
        this.root.render(<LoadingScreen />);

        let loadingScreen = $("#loading-screen");
        //$.post("", { }).fail(()=> {
            setTimeout(() => {
                loadingScreen.removeClass("animate__fadeIn").addClass("animate__fadeOut");

                setTimeout(()=> {
                    loadingScreen.addClass("d-none");
                    $("#main").remove();

                    this.startChats();
                }, 1200);
            }, 2000);
        //});
    }

    startChats(): void {
        $("#main-app").removeClass("d-none");
        this.chats = [["VoxHAUT", "Hello from bot"]];
        this.startRenderingChats();

        ReactDOMClient.createRoot(document.getElementById('floating-btn-div')).render(<FloatingCircleButton />);
        setTimeout(()=> {
            this.chats = [...this.chats, ["Me", "Hello from me"]];
        }, 2000);
    }

    renderChats(domClient): void {
        domClient.render(
            <>{this.chats.map((chat)=> <BubbleChat sender={chat[0]} message={chat[1]} />)}</>
        );
    }

    startRenderingChats(): void {
        let domClient = ReactDOMClient.createRoot(document.getElementById('main-chats'));
        setInterval(()=> this.renderChats(domClient), 1000);
    }
}

const application = new App();
application.main();