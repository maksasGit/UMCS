import java.util.ArrayList;
import java.util.List;

interface Subject {
    void registerObserver(Observer observer);
    void unregisterObserver(Observer observer);
    void notifyObservers();
}

class MusicPlayer implements Subject {
    private String currentSong;
    private final List<Observer> observers;

    public MusicPlayer() {
        this.observers = new ArrayList<>();
    }

    public void playSong(String song) {
        this.currentSong = song;
        notifyObservers();
    }

    @Override
    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void unregisterObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(currentSong);
        }
    }
}

interface Observer {
    void update(String song);
}

class NowPlayingDisplay implements Observer {
    @Override
    public void update(String song) {
        System.out.println("Now Playing: " + song);
    }
}

class Equalizer implements Observer {
    @Override
    public void update(String song) {
        System.out.println("Equalizer: Adjusting for song - " + song);
    }
}


public class Main {

    public static void main(String[] args) {
        MusicPlayer musicPlayer = new MusicPlayer();

        NowPlayingDisplay nowPlayingDisplay = new NowPlayingDisplay();
        Equalizer equalizer = new Equalizer();

        musicPlayer.registerObserver(nowPlayingDisplay);
        musicPlayer.registerObserver(equalizer);

        musicPlayer.playSong("Bohemian Rhapsody");
        musicPlayer.playSong("Hotel California");
        musicPlayer.playSong("Imagine");

        musicPlayer.unregisterObserver(equalizer);

        musicPlayer.playSong("Stairway to Heaven");
    }
}
