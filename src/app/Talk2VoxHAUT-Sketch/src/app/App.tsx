import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import $ from "jquery";

import BubbleChat from './BubbleChat';
import CannotConnectScreen from './CannotConnectScreen';
import FloatingCircleButton from './FloatingCircleButton';
import LoadingScreen from './LoadingScreen';
import SplashScreen from './SplashScreen';

let Config = {
    server: "http://192.168.1.1:80"
};

class App {
    private root = ReactDOMClient.createRoot(document.getElementById('main'));
    private chats: Array<string[]>;
    private previousHash: string = null;

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
        $.post(Config.server + "/check", { }, (data)=> {
            if(data != "OK")
                return;

            setTimeout(() => {
                loadingScreen.removeClass("animate__fadeIn").addClass("animate__fadeOut");

                setTimeout(()=> {
                    loadingScreen.addClass("d-none");
                    $("#main").remove();

                    this.startChats();
                }, 1200);
            }, 2000);
        }).fail(()=> {
            this.root.render(<CannotConnectScreen />);
        });
    }

    startChats(): void {
        $("#main-app").removeClass("d-none");
        this.chats = [["VoxHAUT", "Hello from bot"]];
        this.startRenderingChats();

        ReactDOMClient.createRoot(document.getElementById('floating-btn-div')).render(<FloatingCircleButton />);
    }

    renderChats(domClient): void {
        domClient.render(
            <>{this.chats.map((chat)=> <BubbleChat sender={chat[0]} message={chat[1]} />)}</>
        );
    }

    startRenderingChats(): void {
        let domClient = ReactDOMClient.createRoot(document.getElementById('main-chats'));
        setInterval(()=> {
            this.renderChats(domClient);

            $.post(Config.server + "/resp", { }, (data)=> {
                if(data["hash"] == this.previousHash)
                    return;

                this.previousHash = data["hash"];
                setTimeout(()=> this.chats = [...this.chats, ["VoxHAUT", data["message"]]], 2200);
            });
        }, 1000);
    }

    sendMessageToVoxHAUT(messageId: string, message: string): void {
        this.chats = [...this.chats, ["Me", message]];

        $("#dialog-options")
            .removeClass("animate__slideInDown")
            .addClass("animate__slideOutUp");

        setTimeout(()=> {
            $("#dialog-options").addClass("d-none");
            $("#message-options-dialog").remove();
        }, 1200);

        $.post(Config.server + "/data?type=" + messageId, { }, ()=> {
        });
    }
}

const application = new App();
application.main();

export { application };