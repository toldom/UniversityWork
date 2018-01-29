package Problem2;

public class AppointmentTester {

    public static void main(String[] args) {

        Appointment apptArray[] = new Appointment[10];

        apptArray[0] = new OneTime(2017, 12, 11, "My birthday");
        apptArray[1] = new Monthly(2017, 12, 1, "New month");
        apptArray[2] = new Daily(2018, 1, 1, "ITS 2018?");
        apptArray[3] = new Appointment(2018, 3, 11, "DBD");

        System.out.println(apptArray[0].OccursOn(2017, 12, 11));
        System.out.println(apptArray[0].description);
        System.out.println(apptArray[1].OccursOn(2019, 1, 1));
        System.out.println(apptArray[1].description);

    }

}
