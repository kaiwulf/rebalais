#include "Rebalais.h"

Manager::~Manager() {
    
}

void Manager::startUp() {
    m_is_started = true;
}

void Manager::shutDown() {
    m_is_started = false;
}

bool Manager::isStarted() const {
    return m_is_started;
}

void Manager::setType(std::string new_type) {
    m_type = new_type;
}

std::string Manager::getType() const {
    return m_type;
}