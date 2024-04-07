

class WebPageInterface {
public:
    WebPageInterface();
    WebPageInterface(const WebPageInterface&) = delete;
    WebPageInterface(const WebPageInterface&&) = delete;

    WebPageInterface operator=(const WebPageInterface&) = delete;
    WebPageInterface operator=(const WebPageInterface&&) = delete;

    virtual ~WebPageInterface();

    int ShowPage();

private:
    int Init();
    int Destructor();


private:
    

};