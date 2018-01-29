package Problem2;

public class Appointment {

    public int appointmentYear, appointmentMonth, appointmentDay;
    public String description;

    public Appointment(int appointmentYear, int appointmentMonth, int appointmentDay, String description) {
        this.appointmentYear = appointmentYear;
        this.appointmentMonth = appointmentMonth;
        this.appointmentDay = appointmentDay;
        this.description = description;
    }

    public Appointment() {
        this.appointmentYear = 0;
        this.appointmentMonth = 0;
        this.appointmentDay = 0;
    }

    public boolean OccursOn(int year, int month, int day) {

        if (this.appointmentYear == year && this.appointmentMonth == month && this.appointmentDay == day) {
            return true;
        } else {
            return false;
        }

    }
}
