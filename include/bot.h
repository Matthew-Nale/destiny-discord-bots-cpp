#ifndef BOT_H
#define BOT_H

#include <string>
#include <map>

class VoiceCommands {
    public:
        //Constructor
        VoiceCommands(std::string name, std::string voice_name, std::string voice_key, std::string voice_model, std::map<std::string, std::string> status_messages);
    
        //Member functions
        void credits();
        void speak();
        void vc_speak();

    private:
        //Variables
        std::string name;
        std::string voice_name;
        std::string voice_key;
        std::string voice_model;
        std::map<std::string, std::string> status_messages;
};

class TextCommands {
    public:
        //Constructor
        TextCommands(std::string name, std::string chat_prompt, std::map<std::string, std::string> status_messages);
    
        //Member functions
        void prompt();
        void reset();
        void chat();
        
    private:
        //Variables
        std::string name;
        std::string chat_prompt;
        std::map<std::string, std::string> status_messages;
};

class Bot {
    public:
        //Constructor
        Bot(std::string name, std::string discord_token, std::string voice_name, std::string voice_key, std::string voice_model, std::string chat_prompt,
        bool use_voice, bool use_text, std::map<std::string, std::string> status_messages);

        //Member functions
        void botInit();
        void cleanMemories();
        void on_ready();

    private:
        //Variables
        std::string name;
        std::string discord_token;
        VoiceCommands voice;
        TextCommands text;
};

#endif