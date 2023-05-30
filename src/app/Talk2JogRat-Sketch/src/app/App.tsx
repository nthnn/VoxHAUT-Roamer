import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import $ from "jquery";

import BubbleChat from './BubbleChat';
import LoadingScreen from './LoadingScreen';
import SplashScreen from './SplashScreen';

let root = ReactDOMClient.createRoot(document.getElementById('main'));
root.render(<SplashScreen />);

class App {
    private chats: Array<string[]>;

    constructor() {
        this.chats = [];
    }

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

        let loadingScreen = $("#loading-screen");
        $.post("", { }).fail(()=> {
            setTimeout(() => {
                loadingScreen.removeClass("animate__fadeIn").addClass("animate__fadeOut");

                setTimeout(()=> {
                    loadingScreen.addClass("d-none");
                    $("#main").remove();

                    this.startChats();
                }, 1200);
            }, 2000);
        });
    }

    startChats(): void {
        $("#main-app").removeClass("d-none");
        this.chats = [["images/jograt-mascot.png", "JogRat", "Hello from bot"]];

        this.renderChats(ReactDOMClient.createRoot(document.getElementById('main-chats')));
        setTimeout(()=> {
            this.chats = [...this.chats, ["images/jograt-mascot.png", "Me", "Hello from me"]];
        }, 2000);
    }

    renderChats(domClient): void {
        setInterval(()=> {
            domClient.render(
                <>
                    {this.chats.map((chat)=> <BubbleChat profile={chat[0]} sender={chat[1]} message={chat[2]} />)}
                </>
            )
        }, 1500);
    }
}

const application = new App();
application.main();