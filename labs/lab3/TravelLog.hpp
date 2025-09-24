
class TravelLog {
public:
    TravelLog();
    void addEntry();
    int getTotalMiles() const;

private:
    int prevTime;
    int totalMiles;
};
