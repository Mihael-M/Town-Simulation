#include <stdio.h>
#include "ResidentHistory.h"

void ResidentHistory::record_snapshot(const Resident& res)
{
    history.push_back(res);
}

const std::vector<Resident>& ResidentHistory::get_history() const
{
    return history;
}

size_t ResidentHistory::get_size() const
{
    return history.size();
}
